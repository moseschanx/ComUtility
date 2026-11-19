# packaging/macos

What turns the macOS build into `ComUtility.app` and the release disk images.

| File | What it is |
|---|---|
| `Info.plist.in` | The app bundle's Info.plist. CMake fills in the name, bundle id (`us.moses-ai.comutility`), version and icon from the target properties in `CMakeLists.txt`; it also declares Retina support, macOS 12 as the minimum, and the local-network notice that macOS shows before the first SSH connection. |

The rest of the macOS packaging is in `CMakeLists.txt` (search for `if(APPLE)`):

- **Icon:** `comutility.icns` is made at build time from `resources/icons/comutility.png` with
  `sips` and `iconutil`, so no `.icns` file is kept in the repository.
- **Bundle:** `cmake --install build --prefix dist` copies the build tree's `ComUtility.app`, puts
  `su-fw` inside it (`Contents/MacOS/su-fw`) and runs `macdeployqt` over both. It then removes
  absolute rpaths and signs the bundle ad hoc.

The disk images (`ComUtility-<version>-macos-arm64.dmg`, `-macos-x64.dmg`) are made by the
`build-macos` job in `.github/workflows/build.yml` with `hdiutil`.

Build and package on a Mac:

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=~/Qt/6.8.3/macos \
      -DCMAKE_OSX_ARCHITECTURES=arm64 -DOPENSSL_ROOT_DIR="$(brew --prefix openssl@3)"
cmake --build build && cmake --install build --prefix dist
codesign --verify --deep --strict dist/ComUtility.app
```
