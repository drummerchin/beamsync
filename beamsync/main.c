//
//  main.c
//  beamsync
//
//  Created by mcmillen on 2017/1/6.
//  Copyright © 2017年 vr2d.cn. All rights reserved.
//

#include <stdio.h>
#include <libgen.h>
#include <CoreGraphics/CoreGraphics.h>

extern void CGSSetDebugOptions(int);
extern void CGSDeferredUpdates(int);

typedef enum {
    disableBeamSync = 0,
    automaticBeamSync = 1,
    forcedBeamSyncMode = 2
} beamSyncMode;


void beamSync(beamSyncMode mode);
void usage(char *cmd);

int main(int argc, const char * argv[])
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "disable") == 0)
        {
            beamSync(disableBeamSync);
        }
        else if (strcmp(argv[1], "enable") == 0)
        {
            beamSync(forcedBeamSyncMode);
        }
        else if (strcmp(argv[1], "auto") == 0)
        {
            beamSync(automaticBeamSync);
        }
        else
        {
            usage(argv[0]);
        }
    }
    else
    {
        usage(argv[0]);
    }
    
    return 0;
}

void beamSync(beamSyncMode mode)
{
    CGSSetDebugOptions(mode ? 0 : 0x08000000);
    CGSDeferredUpdates(mode);
}

void usage(char *cmd)
{
    puts("Control Beam Sync (VSync) to optimze display performance on macOS, especially in virtual machine environment.");
    printf("Usage: %s [options]\n", basename(cmd));
    puts("  options:");
    puts("  disable    Disable beam sync");
    puts("  enable     Enable beam sync");
    puts("  auto       Automatic beam sync");
}
