fn fibonacci_rec(n: int) -> int {
	if  n == 1 || n == 2 { return 1; }
	fibonacci_rec(n - 1) + fibonacci_rec(n - 2)
}

fn main() {
	println!("Which number of the sequence do you want?");
	let mut reader = std::io::stdin();
	let input = reader.read_line().ok().expect("Failed to read line");
	let input_num: Option<int> = from_str(input.as_slice().trim());
	match input_num {
		Some(number) => println!("Here it is: {}", fibonacci_rec(number)),
		None => println!("Hey, put in a number.")
	}
}
