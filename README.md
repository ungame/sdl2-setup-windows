# Como configurar SDL2 com C++ no Windows

- Download MinGW-W64: https://sourceforge.net/projects/mingw-w64/files/
- Versão do MinGW-W64 usada neste projeto: [8.1.0](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/)
- Descompactar e copiar o diretório `mingw64` para `C:\mingw64`
- Adicionar o caminho `C:\mingw64\bin` na variável `Path` do sistema
- Download do SDL2 (Development Libraries): https://www.libsdl.org/download-2.0.php
- Versão do SDL2 usada neste projeto: [2.0.20](https://www.libsdl.org/release/SDL2-devel-2.0.20-mingw.tar.gz)
- Descompactar e copiar os diretórios em `SDL2-2.0.20\x86_64-w64-mingw32\` para  `C:\mingw64\x86_64-w64-mingw32`
- Download SDL2 para imagens (Development Libraries): https://www.libsdl.org/projects/SDL_image/
- Versão do SDL2 para imagens usada neste projeto: [2.0.5](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-mingw.tar.gz)
- Descompactar e copiar os diretórios em `SDL2_image-2.0.5\x86_64-w64-mingw32` para `C:\mingw64\x86_64-w64-mingw32`
- Adicionar o caminho `C:\mingw64\x86_64-w64-mingw32\bin` na variável `Path` do sistema

## Configurar C++ no VsCode

- Abrir projeto no VsCode
- Instalar extensão que suporta C++
- Pressionar `[Ctrl]`+`[shift]`+`[p]`
- Selecionar `C/C++: Edit Configurations (JSON)`
- Adicionar o caminho `"C:\\mingw64\\x86_64-w64-mingw32\\include"` no array `includePath`, ex:

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:\\mingw64\\x86_64-w64-mingw32\\include"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.19041.0",
            "compilerPath": "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30037/bin/Hostx64/x64/cl.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-msvc-x64"
        }
    ],
    "version": 4
}
```

## Compilar

```cmd
g++ -c src/Asset/*.cpp -std=c++14 -m64 -g -Wall -I include
g++ -c src/Animation/*.cpp -std=c++14 -m64 -g -Wall -I include	
g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include
g++ *.o -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

```

## Executar

```cmd
g++ *.o -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
```


