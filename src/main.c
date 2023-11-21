#include <ImageMagick-6/wand/MagickWand.h>
#include <stdio.h>

int main() 
{
  MagickWandGenesis();

  MagickWand* wand = NewMagickWand();
  if(MagickReadImage(wand, "./../images/abstrakt.png") == MagickFalse)
  {
    ExceptionType severity;
    char *description = MagickGetException(wand, &severity);

    // Imprimimos el mensaje de error
    fprintf(stderr, "Error: %s (Severity: %d)\n", description, severity);

    // Liberar la memoria utilizada para el mensaje de error
    description = MagickRelinquishMemory(description);
    fprintf(stderr, "Error al transformar la imagen a escala de grises\n");
    exit(1);
    fprintf(stderr, "Error al leer la imagen");
    exit(1);
  }

  MagickWand* imageCanvas = NewMagickWand();
  PixelWand* pw = NewPixelWand();
  PixelSetColor(pw, "white");
  if(MagickNewImage(imageCanvas, 1170 / 2, 2532 / 2, pw) == MagickFalse)
  {
    ExceptionType severity;
    char *description = MagickGetException(wand, &severity);

    // Imprimimos el mensaje de error
    fprintf(stderr, "Error: %s (Severity: %d)\n", description, severity);

    // Liberar la memoria utilizada para el mensaje de error
    description = MagickRelinquishMemory(description);
    fprintf(stderr, "Error al crear el canvas\n");
    exit(1);
  }
  
  MagickWand* res = NewMagickWand();
  res = MagickTextureImage(imageCanvas, wand);
  if (!res) 
  {
    ExceptionType severity;
    char *description = MagickGetException(wand, &severity);

    // Imprimimos el mensaje de error
    fprintf(stderr, "Error: %s (Severity: %d)\n", description, severity);

    // Liberar la memoria utilizada para el mensaje de error
    description = MagickRelinquishMemory(description);
    fprintf(stderr, "Error al transformar la imagen a tiles\n");
    exit(1);
  }

  if (MagickWriteImage(res, "./../images/output_gray2.png") == MagickFalse) 
  {
      ExceptionType severity;
      char *description = MagickGetException(wand, &severity);

      // Imprimimos el mensaje de error
      fprintf(stderr, "Error: %s (Severity: %d)\n", description, severity);

      // Liberar la memoria utilizada para el mensaje de error
      description = MagickRelinquishMemory(description);

      fprintf(stderr, "Error al escribir la imagen de salida\n");
      exit(1);
  }

  DestroyPixelWand(pw);
  DestroyMagickWand(wand);
  DestroyMagickWand(imageCanvas);

  MagickWandTerminus();
  return 0;
}
