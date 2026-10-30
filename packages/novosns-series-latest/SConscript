import os
from building import *

objs = []
cwd  = GetCurrentDir()

if GetDepend(['SOC_SERIES_NS800RT7']):
    objs = objs + SConscript('NS800RT7XXX/SConscript')

Return('objs')