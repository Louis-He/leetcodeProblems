class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        res = ""
        alphabetIndex = [0, 1, 2, 3, 4, 
                         10, 11, 12, 13, 14, 
                         20, 21, 22, 23, 24,
                         30, 31, 32, 33, 34,
                         40, 41, 42, 43, 44,
                         50]
        
        currentPos = 0
        target = target.encode('ascii')
        for letter in target:
            letter -= 97
            letterCoor = alphabetIndex[letter]
            
            while(currentPos != letterCoor):
                currentTens = math.floor(currentPos / 10)
                letterTens = math.floor(letterCoor / 10)
                currentOnes = currentPos % 10
                letterOnes = letterCoor % 10
                    
                if(currentTens > letterTens):
                    res += "U"
                    currentPos -= 10
                elif(currentTens < letterTens and currentPos <= 40):
                    res += "D"
                    currentPos += 10
                else:
                    if(currentOnes > letterOnes):
                        res += "L"
                        currentPos -= 1
                    elif(currentOnes < letterOnes):
                        res += "R"
                        currentPos += 1
                
            res += "!"
        return res
