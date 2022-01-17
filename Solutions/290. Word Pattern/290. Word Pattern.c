bool wordPattern(char* pattern, char* str) {
    int strCount = 0;
    int patternSize = strlen(pattern);
    char** translate = calloc(26, sizeof(char*));
    char *token;

    token = strtok(str, " ");
    while( token != NULL && strCount < patternSize) 
    {
        if(!translate[pattern[strCount] - 'a'])
        {
            translate[pattern[strCount] - 'a'] = token;
        }
        else
        {
            if(strcmp(translate[pattern[strCount] - 'a'], token))
            {
                return false;
            }
        }
        token = strtok(NULL, " ");
        strCount++;
    }
    
    
    if(strCount < patternSize || token != NULL) return false;
    
    for(int i = 0; i < 25; i++)
    {
        if(translate[i])
        {
        
            for(int j = i+1; j < 26; j++)
            {
                if(translate[j])
                {
                    if(strcmp(translate[i], translate[j]) == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
  
    return true;
}