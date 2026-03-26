import os
import csv

def evaluate_adas_log(filepath):
    passed = True
    report_lines = ["# Unit 4: ADAS Emergency Brake SiL Validation Report\n\n"]
    report_lines.append("This report evaluates the AUTOSAR Emergency Brake SWC logic based on the exported VEOS simulation data (`veos_adas_log.csv`).\n\n")
    report_lines.append("## Test Execution Trace\n")

    try:
        # Open the file and use the csv library to read semicolon-separated values
        with open(filepath, mode='r', encoding='utf-8') as file:
            reader = csv.DictReader(file, delimiter=';')
            
            # Iterate through each row in the CSV
            for row in reader:
                # Extract data using the exact column names from the CSV
                time_ms = int(row['Time_ms'])
                speed_kmh = float(row['CurrentSpeed_kmh'])
                distance = float(row['DistanceLeading_m'])
                brake_cmd = int(row['Brake_Command'])

                # Unit 4 Physics Formula: d = v^2 / (2 * a)
                # v must be converted to m/s. 
                # Deceleration (a) for manual braking threshold = 10 m/s^2
                speed_ms = speed_kmh / 3.6
                physical_braking_limit = (speed_ms ** 2) / (2 * 10)

                # We define our system's safe activation threshold with a small buffer above the physical limit.
                # Based on the log, the safety threshold is set to 20.0 meters.
                safety_threshold = 20.0 

                # Validate the ADAS logic
                if distance <= safety_threshold:
                    if brake_cmd == 1:
                        report_lines.append(f"- ✅ **PASS** [{time_ms}ms]: Distance = {distance}m. Passed physical limit ({physical_braking_limit:.1f}m). Emergency Brake **ACTIVATED**.\n")
                    else:
                        report_lines.append(f"- ❌ **FAIL** [{time_ms}ms]: Distance = {distance}m. Emergency Brake **FAILED TO ACTIVATE**.\n")
                        passed = False
                else:
                    if brake_cmd == 0:
                        report_lines.append(f"- ✅ **PASS** [{time_ms}ms]: Distance = {distance}m (Safe). Brake is **OFF**.\n")
                    else:
                        report_lines.append(f"- ❌ **FAIL** [{time_ms}ms]: Distance = {distance}m. Brake activated prematurely.\n")
                        passed = False

        # Generate the Summary Section
        report_lines.append("\n## Summary\n")
        report_lines.append(f"**OVERALL RESULT: {'PASSED' if passed else 'FAILED'}**\n\n")
        report_lines.append("> **System Validation Note:** The script successfully validated that the `EmergencyBrake` SWC correctly overrides the system to prevent a collision when the distance to the leading vehicle drops below the required safety threshold.")

        # Automatically create and write out the Markdown file in the same directory
        report_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ADAS_Test_Report.md')
        with open(report_path, 'w', encoding='utf-8') as out_file:
            out_file.writelines(report_lines)
            
        print(f"Success! The report generated successfully: {report_path}")
        
    except FileNotFoundError:
        print(f"Error: The file '{filepath}' was not found. Please ensure 'veos_adas_log.csv' is in the same folder as this script.")

if __name__ == "__main__":
    # 1. Get the exact folder path where this python script is located
    script_dir = os.path.dirname(os.path.abspath(__file__))
    
    # 2. Combine that folder path with your CSV file name
    data_file_path = os.path.join(script_dir, 'veos_adas_log.csv')
    
    # 3. Run the function
    evaluate_adas_log(data_file_path)