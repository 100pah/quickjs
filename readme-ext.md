# Modified based on bellard/quickjs

## All extended macros
```s
# Enable all debug features.
-D QUICKJS_EXT_JS_DEBUG
# Enable vscode breakpoint.
-D QUICKJS_EXT_JS_DEBUG_ADDRESS=0.0.0.0:8567
# Enable print log in quickjs.
-D QUICKJS_EXT_LOG_LEVEL_DEBUG
# If using on Android.
-D QUICKJS_EXT_PLATFORM_ANDROID
# If print JS debugger communication log for debug the debugger itself.
-D QUICKJS_EXT_JS_DEBUG_PRINT_LOG
```

## Print log in quickjs
Use `-D QUICKJS_EXT_LOG_LEVEL_DEBUG` (and `-D QUICKJS_EXT_PLATFORM_ANDROID` if needed).

## Print JS line number
+ Compile using
    ```s
    -D QUICKJS_EXT_JS_DEBUG
    -D QUICKJS_EXT_LOG_LEVEL_DEBUG
    -D QUICKJS_EXT_PLATFORM_ANDROID # If needed
    ```
+ Add print code somewhere in `quickjs.c`
    ```c
    static JSValue JS_CallInternal(JSContext *caller_ctx, JSValueConst func_obj,
                                JSValueConst this_obj, JSValueConst new_target,
                                int argc, JSValue *argv, int flags)
        // ...
            CASE(OP_tail_call_method):
                {
                    call_argc = get_u16(pc);    js_debugger_current_location_print(ctx, pc);
                    // ...
                }
    }
    ```

## Add vscode JS debugger

Copied from:
+ https://github.com/koush/quickjs
+ https://github.com/koush/vscode-quickjs-debug

### Usage (attach mode) (remote available):

1. Install vscode extension: [QuickJS Debugger](https://github.com/koush/vscode-quickjs-debug)
2. Compile quickjs with
    ```s
    -D QUICKJS_EXT_JS_DEBUG
    -D QUICKJS_EXT_JS_DEBUG=0.0.0.0:8567
    ```
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

