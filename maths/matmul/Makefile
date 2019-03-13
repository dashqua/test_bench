dim=2

c: clean 
	@rm -f c.out
	@gcc matmul.c -o c.out
	@./c.out $(dim) 

ocaml:
	@ocaml matmul.ml $(dim)

clean:
	@rm -rf *~ *.out
