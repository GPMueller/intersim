import pyintersim.corelib as corelib
import ctypes

### Load Library
_core = corelib.LoadCoreLibrary()

### State wrapper class to be used in 'with' statement
class State:
    """Wrapper Class for the State"""

    def __init__(self):
        self.p_state = setup()

    def __enter__(self):
        return self.p_state

    def __exit__(self, exc_type, exc_value, traceback):
        delete(self.p_state)


### Setup State
_State_Setup = _core.State_Setup
_State_Setup.argtypes = None
_State_Setup.restype = ctypes.c_void_p
def setup():
    return _State_Setup()

### Delete State
_State_Delete = _core.State_Delete
_State_Delete.argtypes = [ctypes.c_void_p]
_State_Delete.restype = None
def delete(p_state):
    return _State_Delete(p_state)