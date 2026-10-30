"""Offline summary of original UART logs; no board access or motor commands."""
import json
from pathlib import Path
import re

base=Path(__file__).parent
result={}
for folder in sorted(base.iterdir()):
    if not folder.is_dir() or not (folder/'uart.jsonl').exists():continue
    rows=[json.loads(line) for line in (folder/'uart.jsonl').read_text().splitlines()]
    diag=[dict(re.findall(r'\b(\w+)=([^\s]+)',r['output'])) for r in rows if r['command']=='diag']
    diag=[v for v in diag if {'peak_mA','isr','overflow'}<=v.keys()]
    run=(folder/'run.log').read_text(errors='replace')
    stages=json.loads((folder/'stages.json').read_text()) if (folder/'stages.json').exists() else []
    result[folder.name]={
        'sequence_passed':'PASS: bounded sweep' in run,
        'stages':[{k:v[k] for k in ('target_rpm','max_error_rpm','mean_error_rpm','steady_clips')} for v in stages],
        'peak_mA':max((int(v['peak_mA']) for v in diag),default=0),
        'isr_max_us':max((int(v['isr'].split('/')[1])/400 for v in diag),default=0),
        'overflow_max':max((int(v['overflow']) for v in diag),default=0),
        'bus_min_mV':min((int(v['bus_min_mV']) for v in diag if int(v.get('bus_min_mV',1000000))<1000000),default=None),
        'entry_max_us':max((int(v.get('entry_max_cycles',0))/400 for v in diag),default=0),
        'commands':[r['command'] for r in rows if r['command'].startswith('motor owner')]}
print(json.dumps(result,ensure_ascii=False,indent=2))
