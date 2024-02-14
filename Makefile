TESTS_PATH = ./saalarco-tests

run-tests:
	@make run-tests -C $(TESTS_PATH)

fclean:
	@make fclean -C $(TESTS_PATH)