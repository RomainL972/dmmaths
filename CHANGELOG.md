# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]
### Added
- A DMMaths class that manages the logic (old main.cpp)
- more getters and setters
- A LogType enum in Logger

### Changed
- source files are now in the src subdirectory
- header files are now in the include subdirectory
- Turn renamed to TurnManager
- PilesManager doesn't manager turns and counter anymore because DMMaths does
- Logging can be to stdout, file or none. Tester doesn't use it yet so it's broken for now

## [0.3.1] - 2019-06-14
### Added
- This Changelog

### Fixed
- Compatibility with clang and python2.7

## [0.3.0] - 2019-05-14
### Added
- Ability to log every move to moves.txt
- Python program to display the result with animated rectangles

### Changed
- Complete README

### Removed
- Limit on Tester

## [0.2.0] - 2019-05-11
### Added
- a Tester program that checks incrementally the result for each number of
disques
- GCC -Ofast flag
- a logger (logs number of moves to log.txt)

### Changed
- error messages are sent to the logger

### Fixed
- the program now works with any number of disques (the number of moves is wrong
  after int limit)

## [0.1.0] - 2019-05-10
### Added
- a program that works with a number of disques smaller than 5
- Cmake as the build system
- MIT license
- Almost empty README

[Unreleased]: https://github.com/RomainL972/dmmaths/compare/v0.3.1...HEAD
[0.3.1]: https://github.com/RomainL972/dmmaths/compare/v0.3.0...v0.3.1
[0.3.0]: https://github.com/RomainL972/dmmaths/compare/v0.2.0...v0.3.0
[0.2.0]: https://github.com/RomainL972/dmmaths/compare/v0.1.0...v0.2.0
[0.1.0]: https://github.com/RomainL972/dmmaths/releases/tag/v0.1.0
