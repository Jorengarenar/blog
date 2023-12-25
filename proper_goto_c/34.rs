

fn main() {
    'outer: for i in 1..=5 {
        println!("outer iteration (i): {i}");

        '_inner: for j in 1..=200 {
            println!("    inner iteration (j): {j}");
            if j >= 3 {
                break; // breaks from inner loop, lets outer loop continue
            }
            if i >= 2 {
                break 'outer; // breaks from outer loop, and directly to "Done!"
            }
        }
    }

    println!("Done!");
}
