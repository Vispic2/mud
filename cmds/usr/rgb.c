// Escape Sequences
#define CSI ESC + "[" /* Control Sequence Introducer */
// CSI Color Sequences
#define SGR(x) CSI + x + "m"                                      /* ANSI color code (Select Graphic Rendition) */
#define FCC(x) CSI + "38;5;" + x + "m"                            /* Foreground 256 color code */
#define BCC(x) CSI + "48;5;" + x + "m"                            /* Background 256 color code */
#define RGB(r, g, b) CSI + "38;2;" + r + ";" + g + ";" + b + "m"  /* Foreground 24 bit rgb color code */
#define BRGB(r, g, b) CSI + "48;2;" + r + ";" + g + ";" + b + "m" /* Background 24 bit rgb color code */

int main(object me, string arg)
{
    int *rgb = ({0x00, 0x33, 0x66, 0x99, 0xcc, 0xff});

    printf("ANSI颜色测试：\n");
    for (int i = 30; i < 50; i++)
    {
        printf(SGR(i) "%d. 你好ABC" NOR, i);
        if (i % 5)
        {
            write("\t");
        }
        else
        {
            write("\n");
        }
    }

    printf("\n256颜色测试：\n");
    for (int i = 0; i < 256; i++)
    {
        printf(FCC(i) "%3d. 你好ABC" NOR, i);
        if (i % 5)
        {
            write("\t");
        }
        else
        {
            write("\n");
        }
    }

    printf("\nRGB颜色测试：\n");
    for (int r = 0; r < sizeof(rgb); r++)
    {
        for (int g = 0; g < sizeof(rgb); g++)
        {
            for (int b = 0; b < sizeof(rgb); b++)
            {
                printf(RGB(rgb[r], rgb[g], rgb[b]) "%'0'2x%'0'2x%'0'2x\t" NOR, rgb[r], rgb[g], rgb[b]);
            }
            write("\n");
        }
        write("\n");
    }

    return 1;
}