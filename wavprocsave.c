#include <stdio.h>
#include <stdlib.h>

#define MODE 1

int main()
{
    int ch;

    long unsigned stereo;
    long unsigned sample_rate;
    long unsigned bits_sample;
    long unsigned by_sec;
    long unsigned blck_align;

    for (int i = 0; i < 4; i++) // check 4 bytes for "RIFF"
    {
        ch = getchar();

        switch (ch)
        {
        case 'R':
            if (i != 0)
                fprintf(stderr, "Error! ''RIFF'' not found\n");
            break;

        case 'I':
            if (i != 1)
                fprintf(stderr, "Error! ''RIFF'' not found\n");
            break;

        case 'F':
            if (i != 2 && i != 3)
                fprintf(stderr, "Error! ''RIFF'' not found\n");
            break;

        default:
            fprintf(stderr, "Error! ''RIFF'' not found\n");
            break;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for SizeOf
    {
        ch = getchar();
        long unsigned num;

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
            fprintf(stderr, "size of file: %lu\n", num);
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for "WAVE"
    {
        ch = getchar();

        switch (ch)
        {
        case 'W':
            if (i != 0)
                fprintf(stderr, "Error! ''WAVE'' not found\n");
            break;

        case 'A':
            if (i != 1)
                fprintf(stderr, "Error! ''WAVE'' not found\n");
            break;

        case 'V':
            if (i != 2)
                fprintf(stderr, "Error! ''WAVE'' not found\n");
            break;

        case 'E':
            if (i != 3)
                fprintf(stderr, "Error! ''WAVE not found\n");
            break;

        default:
            fprintf(stderr, "Error! ''WAVE'' not found\n");
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
                fprintf(stderr, "Error! ''fmt '' not found\n");
            break;

        case 'm':
            if (i != 1)
                fprintf(stderr, "Error! ''fmt '' not found\n");
            break;

        case 't':
            if (i != 2)
                fprintf(stderr, "Error! ''fmt '' not found\n");
            break;

        case ' ':
            if (i != 3)
                fprintf(stderr, "Error! ''fmt '' not found\n");
            break;

        default:
            fprintf(stderr, "Error! ''fmt '' not found\n");
            break;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for format chunk
    {
        ch = getchar();
        long unsigned format;

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
            fprintf(stderr, "size of format chunk: %lu\n", format);
        }

        if (format != 16)
        {
            fprintf(stderr, "Error! size of format chunk should be 16\n");
            break;
        }
    }

    for (int i = 0; i < 2; i++) // check the next 2 bytes  for WAVE FORMAT
    {
        ch = getchar();
        long unsigned wave_format;

        if (i == 0)
        {
            wave_format = ch;
            fprintf(stderr, "WAVE type format: %lu\n", wave_format);
        }

        if (i == 1)
        {
            ch = ch << 8;
            wave_format += ch;
        }

        if (wave_format != 1)
        {
            fprintf(stderr, "Error! WAVE type format should be 1\n");
            break;
        }
    }

    for (int i = 0; i < 2; i++) // check the next 2 bytes for stereo
    {
        ch = getchar();

        if (i == 0)
        {
            stereo = ch;
            fprintf(stderr, "mono/stereo : %lu\n", stereo);
        }

        // if (i = 1)
        // {
        //     ch = ch << 8;
        //     // stereo += ch;
        // }

        if (stereo != 1 && stereo != 2)
        {
            fprintf(stderr, "Error! mono/stereo should be 1 or 2\n");
            break;
        }
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
            fprintf(stderr, "sample rate: %lu\n", sample_rate);
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
            fprintf(stderr, "bytes/sec: %lu\n", by_sec);
        }

        // if (by_sec != sample_rate * blck_align)
        // {
        //     fprintf(stderr, "Error! bytes/second should be sample rate * block alignment\n");
        //     break;
        // }
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
            fprintf(stderr, "block alignment: %lu\n", blck_align);
        }

        // if (blck_align != (bits_sample / 8) * stereo)
        // {
        //     fprintf(stderr, "Error! block alignment should be (bits per sample / 8) * mono/stereo");
        //     break;
        // }
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
            fprintf(stderr, "bits/sample: %lu\n", bits_sample);
        }

        if (bits_sample != 8 && bits_sample != 16)
        {
            fprintf(stderr, "Error! bits/sample should be 8 or 16");
            break;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for "data"
    {
        ch = getchar();

        switch (ch)
        {
        case 'd':
            if (i != 0)
                fprintf(stderr, "Error! ''data'' not found\n");
            break;

        case 'a':
            if (i != 1 && i != 3)
                fprintf(stderr, "Error! ''data'' not found\n");
            break;

        case 't':
            if (i != 2)
                fprintf(stderr, "Error! ''data'' not found\n");
            break;

        default:
            fprintf(stderr, "Error! ''data'' not found\n");
            break;
        }
    }

    for (int i = 0; i < 4; i++) // check the next 4 bytes for SizeOfData
    {
        ch = getchar();

        long unsigned size_of_data;

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
            fprintf(stderr, "size of data chunk: %lu\n", size_of_data);
        }
    }

    return 0;
}