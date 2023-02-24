 // This function checks if the human has enough pieces to play
    bool humanhasPieces(char arr[8][8]){
        bool check = false;
        for (int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(arr[i][j] == humanpieces[0].type)
                    check = true;
            }
        }
        return check;
    }

    // This function checks if the computer has enough pieces to play
    bool computerhasPieces(char arr[8][8]){
        bool check = false;
        for (int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(arr[i][j] == computerpieces[0].type)
                    check = true;
            }
        }
        return check;
    }