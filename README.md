# raylibtools
 
Una pequeña biblioteca de utilidades en C para proyectos hechos con [raylib](https://www.raylib.com/). Incluye un sistema de botones (simples, con texto y con textura), utilidades de texto, un generador de números aleatorios (PCG) y un temporizador simple.
 
## Contenido
 
```
.
├── buttons/
│   ├── button.c / button.h            # Botón base
│   ├── textbutton.c / textbutton.h    # Botón con texto
│   └── texturebutton.c / texturebutton.h  # Botón con textura/sprite
├── utils/
│   ├── rng.c / rng.h                  # Generador de números aleatorios (PCG)
│   ├── text.c / text.h                # Utilidad de texto
│   └── timer.c / timer.h              # Temporizador
├── scenes/
│   └── screen.c / screen.h            # Sistema básico de escenas (en desarrollo)
├── raylibtools.h                      # Header único que incluye todo lo anterior
└── Makefile
```
 
## Requisitos
 
- **GCC** (u otro compilador compatible con C99)
- **raylib** instalada en el sistema (headers y librería)
- Sistema Linux (el `Makefile` enlaza con `-lGL -lpthread -ldl -lrt -lX11`, típico de Linux/X11)
### Instalar raylib en Linux (Debian/Ubuntu)
 
```bash
sudo apt update
sudo apt install build-essential git cmake libasound2-dev libx11-dev \
  libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev
git clone https://github.com/raysan5/raylib.git
cd raylib/src
make PLATFORM=PLATFORM_DESKTOP
sudo make install
```
 
Verifica que raylib quedó instalada correctamente:
 
```bash
pkg-config --libs raylib
```
 
## Instalación de raylibtools
 
1. Clona este repositorio dentro de tu proyecto (por ejemplo como submódulo o carpeta hermana):
```bash
git clone <url-de-este-repo> raylibtools
```
 
2. En tu propio código, incluye el header general:
```c
#include "raylibtools/raylibtools.h"
```
 
Esto te da acceso a `Button`, `TextButton`, `TextureButton`, `RNG`, `Text` y `Timer` en un solo `#include`.
 
3. Compila enlazando los archivos `.c` de la biblioteca junto con tu `main.c`. Puedes usar el `Makefile` incluido como referencia o adaptarlo a tu proyecto:
```make
OBJ = main.o \
      buttons/button.o \
      buttons/textbutton.o \
      buttons/texturebutton.o \
      utils/rng.o \
      utils/text.o \
      utils/timer.o
 
$(TARGET): $(OBJ)
	gcc $(OBJ) -o $(TARGET) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```
 
4. Compila con:
```bash
make
```
 
Esto genera el ejecutable `raylibTest` (puedes renombrar `TARGET` en el `Makefile`).
 
> **Nota:** el `Makefile` actual espera que tu archivo principal se llame `main.c` y esté en la raíz del proyecto, junto a las carpetas `buttons/` y `utils/`.
 
## Uso
 
### 1. Botón simple (`Button`)
 
```c
#include "raylibtools.h"
 
Button myButton = SetButton(RectangleBounds(400, 300, 200, 60), RED);
 
// dentro del bucle de juego:
if (HandleButton(&myButton)) {
    // se hizo clic sobre el botón
}
```
 
`HandleButton` dibuja el botón y devuelve `true` si fue clicado ese frame. Si prefieres separar dibujo e input, usa `DrawButton()` e `InputButton()` por separado.
 
### 2. Botón con texto (`TextButton`)
 
```c
Text label = MakeText("Jugar", 24, WHITE);
TextButton playButton;
MakeTextButton(&playButton, RectangleBounds(400, 300, 200, 60), label, DARKGRAY);
 
// en el bucle:
if (HandleTextButton(&playButton)) {
    // acción del botón
}
```
 
El botón se ajusta automáticamente al tamaño del texto (con un padding basado en el `fontSize`). Puedes cambiar el texto o color en caliente:
 
```c
ChangeTextButton(&playButton, MakeText("Pausa", 24, WHITE));
ChangeTextColor(&playButton, YELLOW);
```
 
### 3. Botón con textura (`TextureButton`)
 
```c
TextureButton iconButton;
MakeTextureButton(&iconButton, RectangleBounds(100, 100, 64, 64), "assets/icon.png");
 
// en el bucle:
if (HandleTextureButton(&iconButton)) {
    // acción
}
 
// al finalizar el programa:
UnloadTextureButton(&iconButton);
```
 
Puedes redimensionar (y voltear con valores negativos) con `ResizeTextureButton`:
 
```c
ResizeTextureButton(&iconButton, (Vector2){-64, 64}); // voltea horizontalmente
```
 
### 4. Números aleatorios (`RNG`)
 
Generador PCG independiente del `rand()` estándar, útil si necesitas varias secuencias reproducibles.
 
```c
RNG rng;
rng_seed(&rng, 12345, 1); // semilla, secuencia
 
int dado = rng_range(&rng, 1, 6);
float t = rng_float01(&rng);        // [0, 1)
float x = rng_float(&rng, -5, 5);   // rango arbitrario
int moneda = rng_bool(&rng);        // 0 o 1
```
 
### 5. Texto (`Text`)
 
```c
Text titulo = MakeText("Mi Juego", 40, BLACK);
DrawText(titulo.text, 100, 50, titulo.fontSize, titulo.textColor);
```
 
`MakeText` calcula automáticamente `textWidth` con `MeasureText`, útil para centrar texto manualmente.
 
### 6. Temporizador (`Timer`)
 
```c
Timer cooldown;
TimerStart(&cooldown, 2.0f); // 2 segundos
 
// en el bucle:
TimerUpdate(&cooldown);
if (TimerDone(&cooldown)) {
    // ha pasado el tiempo
    TimerReset(&cooldown);
}
```
 
### 7. Escenas (`Scene`) — en desarrollo
 
El módulo `scenes/screen.h` define una estructura básica pensada para manejar múltiples pantallas (menú, juego, pausa, etc.) mediante punteros a funciones `update`/`draw`:
 
```c
typedef struct Scene {
  SceneFn update;
  SceneFn draw;
} Scene;
```
 
Actualmente `RunScene` y `SwitchScene` están sin implementar; son un punto de partida para quien quiera construir un gestor de escenas sobre esta base.
 
## Ejemplo mínimo completo
 
```c
#include "raylib.h"
#include "raylibtools.h"
 
int main(void) {
    InitWindow(800, 600, "Demo raylibtools");
    SetTargetFPS(60);
 
    Text label = MakeText("Clic aquí", 20, WHITE);
    TextButton button;
    MakeTextButton(&button, RectangleBounds(400, 300, 200, 50), label, DARKBLUE);
 
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
 
        if (HandleTextButton(&button)) {
            ChangeTextColor(&button, RED);
        }
 
        EndDrawing();
    }
 
    CloseWindow();
    return 0;
}
```
 
## Limpieza de la compilación
 
```bash
make clean
```
 
Elimina todos los `.o` y el ejecutable generado.
 
## Contribuir
 
Si quieres extender la biblioteca (por ejemplo, terminar el sistema de escenas), sigue la misma convención de separar `.h` (declaraciones) de `.c` (implementación) por módulo, y agrega los nuevos objetos al `OBJ` del `Makefile`.
 
## Licencia

Esta biblioteca se distribuye bajo la **Licencia Pública General de GNU v3.0 (GPLv3)**.

Eres libre de:
- Usar, modificar y distribuir este software
- Acceder al código fuente completo

Con la condición de que:
- Cualquier obra derivada también debe ser licenciada bajo GPLv3
- Debes incluir una copia de la licencia en tus distribuciones
- Debes documentar los cambios realizados

**No se permite el uso comercial directo sin respetar estos términos.**

Para más detalles, consulta: https://www.gnu.org/licenses/gpl-3.0.html
