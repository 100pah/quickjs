# Mod based on bellard/quickjs

## Add vscode JS debugger

Copied from:
+ https://github.com/koush/quickjs
+ https://github.com/koush/vscode-quickjs-debug

### Usage (attach mode) (remote available):

1. Install vscode extension: [QuickJS Debugger](https://github.com/koush/vscode-quickjs-debug)
2. Compile quickjs with `-D QUICKJS_EXT_JS_DEBUG=0.0.0.0:8567`.
3. Modify `.vscode/launch.json`
```json
// .vscode/launch.json
{
    "version": "0.2.0",
    "configurations": [

        // Check details:
        // https://github.com/koush/vscode-quickjs-debug/blob/master/src/sourcemapArguments.ts
        {
            "name": "js-talos-qjs-debugger",
            // type: "quickjs" is provided by https://github.com/koush/vscode-quickjs-debug
            "type": "quickjs",
            "request": "attach",
            // "localRoot" is not mandatory.
            // If you run your JS code via `JSValue JS_Eval(..., const char *filename, ...)`
            // the `filename` must be consistent with the file path sent by vscode,
            // (See `js_debugger_check_breakpoint` in `quickjs.c`).
            // If "localRoot" is specified here, the file path sent by vscode is the relative
            // path based on this "localRoot", otherwise it is the absolute path.
            "localRoot": "/the/directory/to/your/js/source/code",
            // See details in https://github.com/koush/vscode-quickjs-debug/blob/master/src/quickjsDebug.ts
            "mode": "connect",
            // Should be the same as that defined in `QUICKJS_EXT_JS_DEBUG`.
            "port": 8567,
        },
        // ...
    ]
}
```
4. Start quickjs program. It will wait for connection. Then start vscode debugger to attach to quickjs program.


### dev
+ If need to print log, specify `-D QUICKJS_EXT_LOG_LEVEL_DEBUG` (and `-D QUICKJS_EXT_PLATFORM_ANDROID` if needed).
