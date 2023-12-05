DIRS := $(shell find . -mindepth 3 -maxdepth 3 -type f -name Makefile | xargs -n1 dirname)

all: $(DIRS)

$(DIRS):
	$(MAKE) -C $@

run-%:
	@$(MAKE) -C $(subst _,/,$*) run --no-print-directory

clean:
	@for dir in $(DIRS); do \
		echo ""; \
		$(MAKE) -C $$dir clean; \
	done


.PHONY: all $(DIRS) day%
