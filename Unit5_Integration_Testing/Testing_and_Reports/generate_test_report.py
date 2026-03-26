import os
import csv

def generate_report(data_file):
    total_tests = 0
    passed_tests = 0
    
    report = ["# Unit 5: ecu.test Execution Summary\n"]
    report.append("| Test Case | Module | Status | Time (ms) |")
    report.append("|-----------|--------|--------|-----------|")
    
    try:
        with open(data_file, mode='r', encoding='utf-8') as file:
            reader = csv.DictReader(file, delimiter=';')
            for row in reader:
                total_tests += 1
                if row['Result'] == 'SUCCESS':
                    passed_tests += 1
                    status_icon = "✅ PASS"
                else:
                    status_icon = "❌ FAIL"
                    
                report.append(f"| {row['Test_Case_ID']} | {row['Module']} | {status_icon} | {row['Execution_Time_ms']} |")
                
        # Calculate success rate safely
        if total_tests > 0:
            success_rate = (passed_tests / total_tests) * 100
            report.insert(1, f"**Overall Success Rate:** {success_rate}%\n")
        else:
            report.insert(1, "**Overall Success Rate:** 0% (No test data found)\n")
        
        # Automatically create and write out the Markdown file in the exact same directory
        report_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'Unit5_Final_Report.md')
        
        with open(report_path, 'w', encoding='utf-8') as out:
            out.write('\n'.join(report))
            
        print(f"Success! Unit 5 Report Generated: {report_path}")

    except FileNotFoundError:
        print(f"Error: The file '{data_file}' was not found. Please ensure 'ecu_test_results.csv' is in the same folder.")

if __name__ == "__main__":
    # 1. Get the exact folder path where this python script is located
    script_dir = os.path.dirname(os.path.abspath(__file__))
    
    # 2. Combine that folder path with your CSV file name
    data_file_path = os.path.join(script_dir, 'ecu_test_results.csv')
    
    # 3. Run the function
    generate_report(data_file_path)