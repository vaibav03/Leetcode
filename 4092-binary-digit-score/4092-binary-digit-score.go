func calculateScore(a int, b int) int {
    s1,s2 := 0,0
    for a>0{
        if a&1 == 1{
            s1+=1
        }
        a = a>>1
    }
    for b>0{
        if b&1 == 1{
            s2+=1
        }
        b = b>>1
    }
    fmt.Println(s1,s2)
    if s1 >= s2{
        return s1 * s2
    } 
    return s2/s1
}