FROM wiiuenv/devkitppc:20200625

WORKDIR tmp_build
COPY . .
RUN make clean && make -j8 && mkdir -p /artifacts/wums && cp -r lib /artifacts/wums && cp -r include /artifacts/wums && cp -r share /artifacts/wums
WORKDIR /artifacts

FROM scratch
COPY --from=0 /artifacts /artifacts