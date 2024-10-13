import os

# List of directories for which to count the files
directories = [
    "AtCoder", "CSES", "Codeforces", "GeeksforGeeks", "HackerRank",
    "Kattis", "Leetcode", "LightOJ", "SPOJ", "UVa"
]

def count_files_in_directory(directory):
    """Counts the number of files in a given directory recursively."""
    total_files = 0
    for root, dirs, files in os.walk(directory):
        total_files += len(files)
    return total_files

def get_badge_color(file_count):
    """Determines the badge color based on file count thresholds."""
    if file_count >= 400:
        return "darkred"
    elif file_count >= 100:
        return "darkorange"
    elif file_count >= 50:
        return "darkblue"
    else:
        return "darkgreen"

def generate_badge_links():
    """Generates shields.io badge links for each directory."""
    badge_lines = []
    total_problems = 0  # Initialize the total count
    badge_lines.append("### Solved Problems Count\n")  # Header
    for directory in directories:
        if os.path.exists(directory):
            file_count = count_files_in_directory(directory)
            total_problems += file_count  # Accumulate the total count
            badge_color = get_badge_color(file_count)
            badge_url = f"https://img.shields.io/badge/{directory}-{file_count}-{badge_color}"
            badge_lines.append(f"![{directory} Badge]({badge_url})\n")
        else:
            badge_lines.append(f"![{directory} Badge](https://img.shields.io/badge/{directory}-Directory_not_found-red)\n")
    
    # Add the total problems solved badge with black color
    total_badge_url = f"https://img.shields.io/badge/Total-{total_problems}-black"
    badge_lines.append("\n")  # Add a blank line before the total badge
    badge_lines.append(f"![Total Badge]({total_badge_url})\n")
    
    return badge_lines

def update_readme(badge_lines):
    """Updates the README.md file with the badge report."""
    with open("README.md", "r") as file:
        lines = file.readlines()

    # Find the section where to update the badges
    start_index = -1
    for i, line in enumerate(lines):
        if line.strip() == "### Solved Problems Count":  # Updated header
            start_index = i
            break

    if start_index != -1:
        # Update the existing section
        lines = lines[:start_index] + badge_lines
    else:
        # Append the new section at the end if not found
        lines += badge_lines

    with open("README.md", "w") as file:
        file.writelines(lines)

if __name__ == "__main__":
    badge_lines = generate_badge_links()
    update_readme(badge_lines)
