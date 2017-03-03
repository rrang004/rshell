#!/bin/bash
(echo A && echo B) || (echo C && echo D)
(echo A) || ls
(ls && echo Test) && junkcommand
(junkcommand) || (echo A)
(junk command || echo K) || echo D
(junk command || echo D) && echo P
