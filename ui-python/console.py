import os
import sys

### Import numpy
import numpy as np

### Make sure to find the core modules
core_dir = os.path.dirname(os.path.expanduser('~/Git/intersim/core/'))
sys.path.insert(0, core_dir)

### Import core library
from pyintersim import state

### Small Test
with state.State() as p_state:
    pass