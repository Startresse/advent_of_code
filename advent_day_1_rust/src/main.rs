use std::fs;

fn main()
{

    let filename = "input.txt";

    let mut contents = fs::read_to_string(filename).expect("Couldn't read file");
    contents.pop();

    let lines: Vec<i32> = contents.split("\n").map(|x| x.parse::<i32>().unwrap()).collect();

    for n in 0..lines.len()
    {
        for m in n..lines.len()
        {
            for i in m..lines.len()
            {
                let a = lines[n];
                let b = lines[m];
                let c = lines[i];
                if (a + b + c) == 2020
                {
                    println!("{} is the result", a * b * c);
                }
            }
        }
    }
}