#!/bin/bash
(echo A && echo B) || (echo C && echo D)
(echo A) || ls
(ls && echo Test) && junkcommand
(junkcommand) || (echo A)
(junkcommand || echo K) || echo D
(junkcommand || echo D) && echo P
([ -e main.cpp ] && echo "main.cpp exists") || echo d
