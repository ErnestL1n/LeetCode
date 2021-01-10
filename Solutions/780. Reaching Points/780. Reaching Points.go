//TLE with this approach didn't happen in go 
func reachingPoints(sx int, sy int, tx int, ty int) bool {
    for tx>sx || ty>sy{
        if tx==ty{
            break
        }
        if tx>ty{
            tx-=ty
        }else{
            ty-=tx
        }
    }
    if tx==sx&&ty==sy{
        return true
    }
    return false
}