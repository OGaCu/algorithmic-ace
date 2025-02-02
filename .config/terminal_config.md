```
# Alias for colored ls output
alias ls='ls -G'

# Load version control info
autoload -Uz vcs_info
precmd_vcs_info() { vcs_info }
add-zsh-hook precmd precmd_vcs_info

# Style the git info
zstyle ':vcs_info:git:*' formats '%b'

# Enable prompt substitution
setopt PROMPT_SUBST

# Set main prompt with username, path, and git branch
PROMPT='%F{green}[%n] %F{blue}%~%f %F{yellow}${vcs_info_msg_0_}%f %B%F{blue}$%f%b '

# Set exit status in right prompt with color
precmd() {
    if [ $? != 0 ]; then
        RPROMPT='%F{red}$?%f'
    else
        RPROMPT='%F{green}$?%f'
    fi
}

# Java path for Homebrew
export PATH="/opt/homebrew/opt/openjdk/bin:$PATH"
```