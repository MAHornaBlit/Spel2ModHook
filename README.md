# Spelunky 2 Mod Hooks
This is a template dll to create Mods for the Windows Store version of Spelunky 2.

Spelunky 2 will look for a file named ```Spel2ModHook.dll``` in the ```%UserProfile%\Documents\Spelunky2\mods``` directory.
It will load the library on boot and will call the ```GetHookFuncsEntry```, passing an allocator function, and a list of function callbacks that will be called when appropriate events happen.
