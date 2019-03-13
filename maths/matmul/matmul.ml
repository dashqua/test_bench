#! /usr/bin/env ocaml

let rec getFirst n = match n with
	| [] -> failwith "empty"
	| [e] -> e
	| e :: _ :: r -> getFirst [e] ;;


print_string "Hello World !\n";;
Random.self_init();;
let j = Random.int 15 ;;
Printf.printf ("%i\n") j ;;

let s1 = Random.get_state ();;
let n = Pervasives.int_of_string Sys.argv.(1) ;;
let ccols = Array.make n 0.00 ;;
let c = Array.make n ccols;;
let bcols = Array.make n (Random.State.int s1 15) ;;
let b = Array.make n bcols;;
let acols = Array.make n (Random.int 15) ;;
let a = Array.make n acols;;

for i = 0 to n-1 do
	for j = 0 to n-1 do
		Printf.printf "%i " a.(i).(j) 
	done;
	Printf.printf "\n"
done;;


