#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

//Initialize the chunk
void initChunk(Chunk* chunk){
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
}

//Writes to the chunk
void writeChunk(Chunk* chunk, uint8_t byte){
    //Reallocates memory for our array if we run out of space
    if (chunk->capacity < chunk->capacity + 1){
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);

    }
    chunk->code[chunk->count] = byte;
    chunk->count++;
}

void freeChunk(Chunk* chunk){
    //Frees the array
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk);
}