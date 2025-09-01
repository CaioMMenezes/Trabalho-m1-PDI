# Projeto de Processamento Digital de Imagens - PDI 2025

Projeto base para a implementção das atividades de M1 e M2. PDI 2025-02

## Estrutura do projeto

```
projeto/
├── CMakeLists.txt
├── app/
│ └── run.cpp
├── include/
│ └── (arquivos .hpp)
├── src/
│ └── (arquivos .cpp)
└── data/
└── (imagens para teste)
```

---

## Pré-requisitos

- Windows com [MSYS2](https://www.msys2.org/) instalado
- Pacotes MSYS2:
  ```bash

  pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-opencv
- No linux: opencv, cmake e g++

## Documentação
- Deve seguir o padrão doxygen

## Nomenclatura
- nome de arquivos: tudo minúsculo
- nome de Classes: CamelCase
- nome de métodos e variáveis (devem ser sugestivos): snake_case