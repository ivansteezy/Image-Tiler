#include <ImageMagick-6/wand/MagickWand.h>
#include <stdio.h>

int main() 
{
  MagickWandGenesis();

  MagickWand* wand = NewMagickWand();
  if(MagickReadImage(wand, "./../images/1.jpg") == MagickFalse)
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

  if (MagickTransformImageColorspace(wand, GRAYColorspace) == MagickFalse) {
      ExceptionType severity;
      char *description = MagickGetException(wand, &severity);

      // Imprimimos el mensaje de error
      fprintf(stderr, "Error: %s (Severity: %d)\n", description, severity);

      // Liberar la memoria utilizada para el mensaje de error
      description = MagickRelinquishMemory(description);
      fprintf(stderr, "Error al transformar la imagen a escala de grises\n");
      exit(1);
  }

  if (MagickWriteImage(wand, "./../images/output_gray.jpg") == MagickFalse) {
      ExceptionType severity;
      char *description = MagickGetException(wand, &severity);

      // Imprimimos el mensaje de error
      fprintf(stderr, "Error: %s (Severity: %d)\n", description, severity);

      // Liberar la memoria utilizada para el mensaje de error
      description = MagickRelinquishMemory(description);

      fprintf(stderr, "Error al escribir la imagen de salida\n");
      exit(1);
  }

  wand = DestroyMagickWand(wand);

  MagickWandTerminus();
  printf("Hola mundo!"); 
  return 0;
}
