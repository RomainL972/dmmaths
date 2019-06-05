# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]
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
