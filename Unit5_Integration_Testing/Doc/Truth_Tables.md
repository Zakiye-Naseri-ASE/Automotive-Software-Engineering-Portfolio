# System Logic & Truth Tables

The testing strategy is derived strictly from a mathematical truth table representing all possible input states and expected SUT behavior.

## Base Truth Table (Variant 2)
[cite_start]This table covers the permutations of the three environmental states affecting the `WiperStatus`.

| `WiperButton` (ID 3) | `CurrentSpeed` (ID 1) | `RainSensor` (ID 2) | Expected `WiperStatus` (ID 4) | Description |
| :---: | :---: | :---: | :---: | :--- |
| Any | Any | 0 | **0** | **Scenario 1:** Wipers OFF |
| Any | Any | 1 | **1** | **Scenario 2:** Wipers ON (Always On Mode) |
| 0   | 0   | 2 | **0** | **Scenario 3:** Auto Mode (Stationary, No Rain) |
| 0   | 1   | 2 | **0** | **Scenario 4:** Auto Mode (Stationary, Raining) |
| >0  | 0   | 2 | **0** | **Scenario 5:** Auto Mode (Moving, No Rain) |
| >0  | 1   | 2 | **1** | **Scenario 6:** Auto Mode (Moving, Raining) |

## High-Priority "Wipers Active" Scenarios
For automated testing, the focus narrows specifically to scenarios where the expected output is strictly `1` (Active).

| WiperButton | RainSensor | Speed | Expected Status | Logical Explanation |
| :---: | :---: | :---: | :---: | :--- |
| 1 | 0 | 0  | 1 | Always ON overrides lack of rain and stationary state |
| 1 | 0 | >0 | 1 | Always ON overrides lack of rain  |
| 1 | 1 | 0  | 1 | Always ON overrides stationary state  |
| 1 | 1 | >0 | 1 | Always ON active in moving rain  |
| 2 | 1 | >0 | 1 | Auto mode active: rain detected and car moving |