function test(invariante) {
    i = 0;
    s = 1;

    if (!invariante(i, s)) {
        console.log(false);
    }

    while (i != Infinity) {
        i = i + 1;
        s = s + i;

        if (!invariante(i, s)) {
            console.log(false, i, s);
            break;
        }
    }
}

test((i, s) => (i<s));