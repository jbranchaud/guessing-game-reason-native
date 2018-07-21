/* Guessing Game */

module Computer = {
  type hint =
    | Match
    | Lower
    | Higher;

  let pick_a_number = upper_bound => {
    Random.init(int_of_float(Unix.time()));
    Random.int(upper_bound);
  };

  let check_guess = (secret: int, guess: int) : hint =>
    switch (Pervasives.compare(secret, guess)) {
    | 0 => Match
    | no_match when no_match < 0 => Lower
    | no_match when no_match > 0 => Higher
    };
};

print_endline("Let's play a guessing game...");

let secret_number = Computer.pick_a_number(100);

let game_over = ref(false);

while (! game_over^) {
  print_string("Enter a guess: ");
  flush(stdout);

  let guess = input_line(stdin) |> int_of_string;

  switch (Computer.check_guess(secret_number, guess)) {
  | Computer.Higher => print_endline("Nope, go higher")
  | Computer.Lower => print_endline("Nope, go lower")
  | Computer.Match =>
    print_endline("Yay, you guessed it 🎉");
    game_over := true;
  };
};