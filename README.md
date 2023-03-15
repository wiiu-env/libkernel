[![Publish Docker Image](https://github.com/wiiu-env/libkernel/actions/workflows/push_image.yml/badge.svg)](https://github.com/wiiu-env/libkernel/actions/workflows/push_image.yml)

# libkernel
Requires the [KernelModule](https://github.com/wiiu-env/KernelModule) to be running via [WUMSLoader](https://github.com/wiiu-env/WUMSLoader).
Requires [wut](https://github.com/devkitPro/wut) for building.
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
COPY --from=ghcr.io/wiiu-env/libkernel:[tag] /artifacts $DEVKITPRO
[...]
```
Replace [tag] with a tag you want to use, a list of tags can be found [here](https://github.com/wiiu-env/libkernel/pkgs/container/libkernel/versions). 
It's highly recommended to pin the version to the **latest date** instead of using `latest`.

## Format the code via docker

`docker run --rm -v ${PWD}:/src ghcr.io/wiiu-env/clang-format:13.0.0-2 -r ./source ./include -i`