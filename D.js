const handle = (input, limit) => {
    const split = input.match(/(\d+|[a-z])/g);

    let string = "";

    let lastCount = 1;

    for (const instruction of split) {
        if (/[a-z]/.test(instruction)) {
            if (string.length + lastCount > limit) return "unfeasible";
            string += instruction.repeat(lastCount);
            lastCount = 1;
            continue;
        }

        if (instruction.length >= 8) return "unfeasible";
        lastCount = Number(instruction);
    }

    return string;
};

const stdin = process.stdin;

let input = ""

stdin.on('data', chunk => input += chunk);
stdin.on('end', () => {
    input.split("\n").forEach((x, index) => {
        if (index === 0) return;
        if (x == "") return;
        const [string, limitString] = x.split(" ");
        process.stdout.write(handle(string, Number(limitString)) + "\n");
    })
})
