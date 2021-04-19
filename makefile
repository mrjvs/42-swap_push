all: checker push_swap

checker:
	$(MAKE) -C checker

push_swap:
	$(MAKE) -C push_swap

.PHONY: checker push_swap
