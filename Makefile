
build:
	emcc wasm_dijkstra.c -o sample.js -s EXPORTED_RUNTIME_METHODS=cwrap -s ENVIRONMENT=web -s NO_FILESYSTEM=1 --no-entry -s EXPORTED_FUNCTIONS=_malloc,_free
