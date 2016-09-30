Extension of MINIX OS which allows user to stop and continue processes.
Process will be stopped by receiving SIGSTOP signal and will start working again when it receives SIGCONT signal.
Only users processes may be stopped.
Stopped processes can receive other signals but they will handle them after SIGCONT signal.
Pushing CTRL+Z sends SIGSTOP signal to all processes from foreground group.

Additional int get_stopped_procs(pid_t * buf) is implemented, which fills buf table with pid's of stopped processes at the moment.




To launch copy folder to usr/src and recompile libraries and kernel.