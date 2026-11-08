func isDigorChar(u rune) bool {
    if (u >= '0' && u<='9') || (u>='a' && u<='z') || (u >= 'A' && u <= 'Z'){
        return true
    } 
    return false
}
func isVowel(u rune) bool {
    if u == 'a' || u == 'e' || u == 'i' || u == 'o' || u == 'u' ||
       u == 'A' || u == 'E' || u == 'I' || u == 'O' || u == 'U' {
        return true
    }
    return false
}
func isValid(word string) bool {
    if len(word) < 3 {
        return false
    }
    vow, cons := 0, 0
    for i := range word {
        pres := rune(word[i])
        if !isDigorChar(pres) {
            return false
        }
        if isVowel(pres) {
            vow = vow + 1
        } else if !(pres >= '0' && pres <= '9') {
            cons = cons + 1
        }
    }
    return cons >= 1 && vow >= 1
}