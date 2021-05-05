.PHONY: clean All

All:
	@echo "----------Building project:[ Jumble_game_4 - Debug ]----------"
	@cd "Jumble_game_4" && "$(MAKE)" -f  "Jumble_game_4.mk"
clean:
	@echo "----------Cleaning project:[ Jumble_game_4 - Debug ]----------"
	@cd "Jumble_game_4" && "$(MAKE)" -f  "Jumble_game_4.mk" clean
