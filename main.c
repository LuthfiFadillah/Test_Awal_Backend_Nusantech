#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int s;
    char** maze;

    //initiate size
    scanf("%d", &s);

    //allocate memory
    maze = (char**)malloc(s * sizeof(char*));
    for(int i = 0; i < s; i++){
        maze[i] = (char*)malloc(s * sizeof(char));
    }

    if (maze == NULL){
        //check if not sucessfully allocated    
        printf("ERROR, UNABLE TO ALLOCATE MEMORY!");
    } else {
        //initiate array
        for(int i=0; i<s; i++){
            for(int j=0; j<s; j++){
                maze[i][j] = '@';
            }
        }

        //create way in and way out
        maze[0][1] = '_';
        maze[s-1][s-2] = '_';
        
        //create empty space
        for(int i = 1; i<s-1; i++){
            if(i%2 == 0){
                if(i%4 == 0){
                    maze[i][1] = '_';
                }
                else{
                    maze[i][s-2] = '_';
                }
            } else {
                for(int j = 1; j<s-1; j++){
                    maze[i][j] = '_';
                }
            }
        }
        
        //print maze
        for(int i=0; i<s; i++){
            for(int j=0; j<s; j++){
                if(maze[i][j] == '_'){
                    printf(" ");
                }else{
                    printf("%c", maze[i][j]);
                }
            }
            printf("\n");
        }
    }

    //free memory
    free(maze);
    return 0;
}
