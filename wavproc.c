#include <stdio.h>
#include <stdlib.h>

#define MODE 1

int main()
{
    int ch;

    unsigned int num = 0;
    unsigned int format = 0;
    unsigned int stereo = 0;
    unsigned int wave_format = 0;
    unsigned int sample_rate = 0;
    unsigned int size_of_data = 0;
    unsigned int bits_sample = 0;
    unsigned int by_sec = 0;
    unsigned int blck_align = 0;

    for (int i = 0; i < 4; i++) // check 4 bytes for "RIFF"
    {
        ch = getchar();

        switch (ch)
        {
        case 'R':
            if (i != 0)
            {
                fprintf(stderr, "Error! ''RIFF'' not found\n");
                return 1;
            }
            break;

        case 'I':
            if (i != 1)
            {
                fprintf(stderr, "Error! ''RIFF'' not found\n");
                return 1;
            }
            break;

        case 'F':
            if (i != 2 && i != 3)
            {
                fprintf(stderr, "Error! ''RIFF'' not found\n");
                return 1;
            }
            break;

        default:
        {
            fprintf(stderr, "Error! ''RIFF'' not found\n");
            return 1;
        }
        break;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for SizeOf
    {
        ch = getchar();

        if (i == 0)
        {
            num = ch;
        }

        if (i == 1)
        {
            ch = ch << 8;
            num += ch;
        }

        if (i == 2)
        {
            ch = ch << 16;
            num += ch;
        }

        if (i == 3)
        {
            ch = ch << 24;
            num += ch;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for "WAVE"
    {
        ch = getchar();

        switch (ch)
        {
        case 'W':
            if (i != 0)
            {
                fprintf(stderr, "Error! ''WAVE'' not found\n");
                return 1;
            }
            break;

        case 'A':
            if (i != 1)
            {
                fprintf(stderr, "Error! ''WAVE'' not found\n");
                return 1;
            }
            break;

        case 'V':
            if (i != 2)
            {
                fprintf(stderr, "Error! ''WAVE'' not found\n");
                return 1;
            }
            break;

        case 'E':
            if (i != 3)
            {
                fprintf(stderr, "Error! ''WAVE not found\n");
                return 1;
            }
            break;

        default:
        {
            fprintf(stderr, "Error! ''WAVE'' not found\n");
            return 1;
        }
        break;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for "fmt "
    {
        ch = getchar();

        switch (ch)
        {
        case 'f':
            if (i != 0)
            {
                fprintf(stderr, "Error! ''fmt '' not found\n");
                return 1;
            }
            break;

        case 'm':
            if (i != 1)
            {
                fprintf(stderr, "Error! ''fmt '' not found\n");
                return 1;
            }
            break;

        case 't':
            if (i != 2)
            {
                fprintf(stderr, "Error! ''fmt '' not found\n");
                return 1;
            }
            break;

        case ' ':
            if (i != 3)
            {
                fprintf(stderr, "Error! ''fmt '' not found\n");
                return 1;
            }
            break;

        default:
        {
            fprintf(stderr, "Error! ''fmt '' not found\n");
            return 1;
        }
        break;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for format chunk
    {
        ch = getchar();

        if (i == 0)
        {
            format = ch;
        }

        if (i == 1)
        {
            ch = ch << 8;
            format += ch;
        }

        if (i == 2)
        {
            ch = ch << 16;
            format += ch;
        }

        if (i == 3)
        {
            ch = ch << 24;
            format += ch;
        }
    }

    for (int i = 0; i < 2; i++) // check the next 2 bytes  for WAVE FORMAT
    {
        ch = getchar();

        if (i == 0)
        {
            wave_format = ch;
        }

        if (i == 1)
        {
            ch = ch << 8;
            wave_format += ch;
        }
    }

    for (int i = 0; i < 2; i++) // check the next 2 bytes for stereo
    {
        ch = getchar();

        if (i == 0)
        {
            stereo = ch;
        }

        // if (i = 1)
        // {
        //     ch = ch << 8;
        //     // stereo += ch;
        // }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for sample rate
    {
        ch = getchar();

        if (i == 0)
        {
            sample_rate = ch;
        }

        if (i == 1)
        {
            ch = ch << 8;
            sample_rate += ch;
        }

        if (i == 2)
        {
            ch = ch << 16;
            sample_rate += ch;
        }

        if (i == 3)
        {
            ch = ch << 24;
            sample_rate += ch;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for bytes per sec
    {
        ch = getchar();

        if (i == 0)
        {
            by_sec = ch;
        }

        if (i == 1)
        {
            ch = ch << 8;
            by_sec += ch;
        }

        if (i == 2)
        {
            ch = ch << 16;
            by_sec += ch;
        }

        if (i == 3)
        {
            ch = ch << 24;
            by_sec += ch;
        }
    }

    for (int i = 0; i < 2; i++) // check the next 2 bytes for block allignment
    {
        ch = getchar();

        if (i == 0)
        {
            blck_align = ch;
        }

        if (i == 1)
        {
            ch = ch << 8;
            blck_align += ch;
        }
    }

    for (int i = 0; i < 2; i++) // check the next 2 bytes for bits per sample
    {
        ch = getchar();

        if (i == 0)
        {
            bits_sample = ch;
        }

        if (i == 1)
        {
            ch = ch << 8;
            bits_sample += ch;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for "data"
    {
        ch = getchar();

        switch (ch)
        {
        case 'd':
            if (i != 0)
            {
                fprintf(stderr, "Error! ''data'' not found\n");
                return 1;
            }
            break;

        case 'a':
            if (i != 1 && i != 3)
            {
                fprintf(stderr, "Error! ''data'' not found\n");
                return 1;
            }
            break;

        case 't':
            if (i != 2)
            {
                fprintf(stderr, "Error! ''data'' not found\n");
                return 1;
            }
            break;

        default:
        {
            fprintf(stderr, "Error! ''data'' not found\n");
            return 1;
        }
        break;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for SizeOfData
    {
        ch = getchar();

        if (i == 0)
        {
            size_of_data = ch;
        }

        if (i == 1)
        {
            ch = ch << 8;
            size_of_data += ch;
        }

        if (i == 2)
        {
            ch = ch << 16;
            size_of_data += ch;
        }

        if (i == 3)
        {
            ch = ch << 24;
            size_of_data += ch;
        }
    }

    fprintf(stderr, "size of file: %u\n", num);

    fprintf(stderr, "size of format chunk: %u\n", format);
    if (format != 16)
    {
        fprintf(stderr, "Error! size of format chunk should be 16\n");
        return 1;
    }

    fprintf(stderr, "WAVE type format: %u\n", wave_format);
    if (wave_format != 1)
    {
        fprintf(stderr, "Error! WAVE type format should be 1\n");
        return 1;
    }

    fprintf(stderr, "mono/stereo : %u\n", stereo);
    if (stereo != 1 && stereo != 2)
    {
        fprintf(stderr, "Error! mono/stereo should be 1 or 2\n");
        return 1;
    }

    fprintf(stderr, "sample rate: %u\n", sample_rate);

    fprintf(stderr, "bytes/sec: %u\n", by_sec);
    if (by_sec != sample_rate * blck_align)
    {
        printf("sample rate = %d, block alignment = %d, bytes/second = %d\n", sample_rate, blck_align, by_sec);
        fprintf(stderr, "Error! bytes/second should be sample rate * block alignment\n");
        return 1;
    }

    fprintf(stderr, "block alignment: %u\n", blck_align);

    fprintf(stderr, "bits/sample: %u\n", bits_sample);
    if (bits_sample != 8 && bits_sample != 16)
    {
        fprintf(stderr, "Error! bits/sample should be 8 or 16");
        return 1;
    }

    if (blck_align != (bits_sample / 8) * stereo)
    {
        fprintf(stderr, "Error! block alignment should be (bits per sample / 8) * mono/stereo");
        return 1;
    }

    fprintf(stderr, "size of data chunk: %u\n", size_of_data);

    return 0;
}