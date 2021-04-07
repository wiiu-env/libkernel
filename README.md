# libkernel
Requires the [KernelModule](https://github.com/Maschell/KernelModule) to be running via [SetupPayload](https://github.com/wiiu-env/SetupPayload).
Requires [wut](https://github.com/decaf-emu/wut) for building.
Install via `make install`.

## Usage
When linking, make sure to add the `libkernel.ld` file to the LDFLAGS.

Example:
```
LDFLAGS	=	-g $(ARCH) $(RPXSPECS) -Wl,-Map,$(notdir $*.map) -T$(WUMS_ROOT)/share/libkernel.ld
```

Make also sure to define 
```
WUMS_ROOT := $(DEVKITPRO)/wums
```
and add `-lkernel` to `LIBS` and `$(WUMS_ROOT)` to `LIBDIRS`.

After that you can simply include `<kernel/kernel.h>` to get access to the kernel functions.

## Use this lib in Dockerfiles.
A prebuilt version of this lib can found on dockerhub. To use it for your projects, add this to your Dockerfile.
```
[...]
COPY --from=wiiuenv/libkernel:[tag] /artifacts $DEVKITPRO
[...]
```
Replace [tag] with a tag you want to use, a list of tags can be found [here](https://hub.docker.com/r/wiiuenv/libkernel/tags). 
It's highly recommended to pin the version to the **latest date** instead of using `latest`.