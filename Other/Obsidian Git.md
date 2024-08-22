# Git

Plugin that allows you to back up your [Obsidian.md](https://obsidian.md/) vault to a remote Git repository (e.g. private repo on GitHub).

Requirements, installation steps (including setup for mobile), tips and tricks, common issues and more can be found in the [documentation](https://publish.obsidian.md/git-doc).

For mobile users see [Mobile](app://obsidian.md/index.html#mobile) section below.

## Highlighted Features

- Automatic vault backup every X minutes
- Pull changes from remote repository on Obsidian startup
- Assign hotkeys for pulling/pushing changes to a remote repository
- Manage different repositories via Git submodules (after enabling this feature in settings)
- The Source Control View allows you to stage and commit individual files. It can be opened with the `Open Source Control View` command.
- The History View shows the commits and their changed files. So basically an integrated `git log`. It can be opened with the `Open History View` command.
- For viewing the history of a file, I strongly recommend you the [Version History Diff](obsidian://show-plugin?id=obsidian-version-history-diff) plugin

### Source Control View

![Source Control View](https://raw.githubusercontent.com/denolehov/obsidian-git/master/images/source-view.png)

### History View

![History View](https://raw.githubusercontent.com/denolehov/obsidian-git/master/images/history-view.png)

## Available Commands

- Changes
    - `List changed files`: Lists all changes in a modal
    - `Open diff view`: Open diff view for the current file
    - `Stage current file`
    - `Unstage current file`
- Commit
    - `Commit all changes`: Only commits all changes without pushing
    - `Commit all changes with specific message`: Same as above, but with a custom message
    - `Commit staged`: Commits only files that have been staged
    - `Commit staged with specific message`: Same as above, but with a custom message
- Backup
    - `Create Backup`: Commits all changes. If "Push on backup" setting is enabled, will also push the commit.
    - `Create Backup with specific message`: Same as above, but with a custom message
    - `Create backup and close`: Same as `Create Backup`, but if running on desktop, will close the Obsidian window. Will not exit Obsidian app on mobile.
- Remote
    - `Push`
    - `Pull`
    - `Edit remotes`
    - `Remove remote`
    - `Clone an existing remote repo`: Opens dialog that will prompt for URL and authentication to clone a remote repo
    - `Open file on GitHub`: Open the file view of the current file on GitHub in a browser window. Note: only works on desktop
    - `Open file history on GitHub`: Open the file history of the current file on GitHub in a browser window. Note: only works on desktop
- Local
    - `Initialize a new repo`
    - `Create new branch`
    - `Delete branch`
    - `CAUTION: Delete repository`
- Source Control View
    - `Open source control view`: Opens side pane displaying [Source control view](app://obsidian.md/index.html#sidebar-view)
    - `Edit .gitignore`
    - `Add file to .gitignore`: Add current file to .gitignore

## Desktop

## Authentication

Authentication may require additional setup. See more in the [Authentication documentation](https://publish.obsidian.md/git-doc/Authentication)

### Obsidian on Linux

- ⚠ Snap is not supported.
- ⚠ Flatpak is not recommended, because it doesn't have access to all system files.

Please use AppImage instead ([Linux installation guide](https://publish.obsidian.md/git-doc/Installation#Linux))

## Mobile

The git implementation on mobile is **very unstable**!

### Restrictions

I am using [isomorphic-git](https://isomorphic-git.org/), which is a re-implementation of Git in JavaScript, because you cannot use native Git on Android or iOS.

- SSH authentication is not supported ([isomorphic-git issue](https://github.com/isomorphic-git/isomorphic-git/issues/231))
- Repo size is limited, because of memory restrictions
- Rebase merge strategy is not supported
- Submodules are not supported

### Performance on mobile

Caution

Depending on your device and available free RAM, Obsidian may

- crash on clone/pull
- create buffer overflow errors
- run indefinitely.

It's caused by the underlying git implementation on mobile, which is not efficient. I don't know how to fix this. If that's the case for you, I have to admit this plugin won't work for you. So commenting on any issue or creating a new one won't help. I am sorry.

**Setup:** iPad Pro M1 with a [repo](https://github.com/Vinzent03/obsidian-git-stress-test) of 3000 files reduced from [10000 markdown files](https://github.com/Zettelkasten-Method/10000-markdown-files)

The initial clone took 0m25s. After that, the most time consuming part is to check the whole working directory for file changes. On this setup, checking all files for changes to stage takes 03m40s. Other commands like pull, push and commit are very fast (1-5 seconds).

The fastest way to work on mobile if you have a large repo/vault is to stage individual files and only commit staged files.

## Contact

The Line Authoring feature was developed by [GollyTicker](https://github.com/GollyTicker), so any questions may be best answered by him.

If you have any kind of feedback or questions, feel free to reach out via GitHub issues or `@Vinadon` on [Obsidian Discord server](https://discord.com/invite/veuWUTm).

This plugin was initial developed by [denolehov](https://github.com/denolehov). Since March 2021, it is [Vinzent03](https://github.com/Vinzent03) who is developing on this plugin.

If you want to support me ([Vinzent03](https://github.com/Vinzent03)) you can support me on Ko-fio

# [The Easiest Way to Setup Obsidian Git (to backup notes)](https://forum.obsidian.md/t/the-easiest-way-to-setup-obsidian-git-to-backup-notes/51429)

[Share & showcase](https://forum.obsidian.md/c/share-showcase/9)

Jan 2023

1 / 8

Jan 2023

Mar 18

[![](https://forum.obsidian.md/letter_avatar_proxy/v4/letter/i/898d66/48.png)](https://forum.obsidian.md/u/ithinkwong)

[ithinkwong](https://forum.obsidian.md/u/ithinkwong)

[Jan 2023](https://forum.obsidian.md/t/the-easiest-way-to-setup-obsidian-git-to-backup-notes/51429 "Post date")

I watched a few videos on how to setup the obsidian-git plugin and it feels like most of them overcomplicate the process. So I decided to write a set of instructions and a video to show how easy it to accomplish this even if you have no idea what “git” is.

By the end of this tutorial, you will be able to sync your notes from Obsidian to Github for free!

1. Create a repository or [fork the md repo 2.1k](https://linked-blog-starter.vercel.app/publish-your-obsidian-notes-with-linked-blog-starter) in github
2. [Download Git 880](https://git-scm.com/downloads)
3. Create a [personal access token 1.8k](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token#creating-a-personal-access-token-classic) from github![create-pat-github.png](https://linked-blog-starter.vercel.app/md_assets/attachments/create-pat-github.png)
4. Install the [Obsidian Git 2.6k](https://github.com/denolehov/obsidian-git/wiki/Installation) community plugin
5. Create a folder to store the repository. (e.g. `remote-blog/`). Set scopes to repo & expiration to no expiration
6. Run the command (CMD/Ctrl + P): `Clone an existing remote repo` ![clone-repo-git-plugin.png](https://linked-blog-starter.vercel.app/md_assets/attachments/clone-repo-git-plugin.png)
7. Paste the URL of the forked repository in the following format

`https://<PERSONAL_ACCESS_TOKEN>@github.com/<USERNAME>/<REPO>.git`

For example it might look like this:

`https://ghp_XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@github.com/ithinkwong/linked-blog-starter-md.git`

7. Then type in the folder you created in step 5 (e.g. `remote-blog/`)
8. Restart Obsidian
9. Make edits to your notes
10. Publish your notes run the command “Obsidian Git: Create backup” by opening the command palette (CMD/Ctrl + P)

![[Pasted image 20240626164849.png]]

If this occurs, go to the cmd of your git install
`C:\Program Files\Git\git-cmd.exe`
and run the commands in the pic above