#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

//Initialize the chunk
void initChunk(Chunk* chunk){
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

//Writes to the chunk
void writeChunk(Chunk* chunk, uint8_t byte, int line){
    //Reallocates memory for our array if we run out of space
    if (chunk->capacity < chunk->capacity + 1){
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);

    }
    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}

void freeChunk(Chunk* chunk){
    //Frees the array
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

int addConstant(Chunk* chunk, Value value){
    //Adds a value to the value array
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}