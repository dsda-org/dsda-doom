# Contributing to dsda-doom

Thank you for your interest in contributing to dsda-doom!

1. [Feature Requests and Bug Reports](#feature-requests-and-bug-reports)
2. [Pull Requests](#pull-requests)
    1. [Demo Desyncs Testing](#demo-desync-testing)
    2. [Performance](#performance)
    3. [Documentation](#documentation)
    4. [Style](#style)
3. [Release Process](#release-process)
4. [LLM / AI Contributions](#llm--ai-contributions)
5. [Contact](#contact)

## Feature Requests and Bug Reports

Feature requests and Bug reports should be filed in the [dsda-doom issue tracker](https://github.com/dsda-org/dsda-doom/issues). If you are unsure if you should file one, you can always ask in our [Discord](https://discord.gg/9paQ52zQUT) or in the [DoomWorld Thread](https://www.doomworld.com/forum/topic/150766).

## Pull Requests

All patches should be sent on GitHub as [pull requests](https://github.com/dsda-org/dsda-doom/pulls). Occasionally we accept patches sent via other methods if appropriate.

If you are looking for a place to start contributing to dsda-doom, take a look at the open [issues](https://github.com/dsda-org/dsda-doom/issues).

Help reviewing other people's pull request is also appreciated.

### Demo Desync Testing

If your contribution has the risk of causing demo desyncs, please run a small suite of demo regression testing in your machine. This can be done by finding some relevant big demos in [dsdarchive.com](https://dsdarchive.com) and running them with your patched build. Let us know about your testing, but rest assured that we will run our full demo testing suite before your pull request is merged.

### Performance

If your changes may affect the performance of dsda-doom, you should benchmark them, and let us know the results. Careful consideration will be taken when deciding if it should be merged.

### Documentation

Code should be commented where appropriate. The existing code can be used as a guidance here, try to blend your patch in. Additionally, commit messages and pull requests should have descriptive comments, we might read them again 10 years down the line.

Most changes should be documented in the next release's patch notes. A simple new line with a user friendly description will usually suffice, but more space can be taken if necessary.

### Style

As this codebase has been modified by hundreds of people over 30 years, and never had a defined coding style, you will find that the style changes from file to file and function to function. The current recommendation is to try to blend you code in, try to use the exact format that was in that place. In the future a strict coding style may be required for new code.

Some contributors like to write their initials before a comment, this has been done historically, so it is still allowed, although not encouraged. The date however, is not desired and should no longer be included.

# Release Process

Before every release the full demo regression testing suite will be ran to ensure that the release is safe to record demos on.

Our releases timeline is divided into 2 periods: minor (v0.0.x) and major (v0.x.0). Note that depending on how busy we are, releases might take a while to happen.

# LLM / AI Contributions

This project does not welcome contributions mainly driven/written/assisted by generative AI, this includes pull requests, issues, comments, reviews or any other text/code/media contribution that will reach the eyes of the maintainers.

# Contact

You can use the [issues](https://github.com/dsda-org/dsda-doom/issues) as a way to contact us.

As a more immediate and direct form of communication, you can contact us in the [Discord](https://discord.gg/9paQ52zQUT) or in the [DoomWorld Thread](https://www.doomworld.com/forum/topic/150766). Alternatively, you can reach out to @Pedro-Beirao by any means you prefer.
