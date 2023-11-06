function compare(pswd1, pswd2) {
    if ((pswd1 == pswd2)&&(pswd1>=8)) {
        let text = "Password validated";
    } else if (pswd1 != pswd2) {
        let text = "Passwords do not match";
    } else if ((pswd1 || pswd2)<8) {
        let text = "Passwords are not 8 characters long";
    }
    return text;
}