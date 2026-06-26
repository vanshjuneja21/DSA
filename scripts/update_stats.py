import requests
import re

USERNAME = "vanshjuneja"

query = """
query getUserProfile($username: String!) {
  matchedUser(username: $username) {
    submitStats {
      acSubmissionNum {
        difficulty
        count
      }
    }
  }
}
"""

url = "https://leetcode.com/graphql"

response = requests.post(
    url,
    json={
        "query": query,
        "variables": {
            "username": USERNAME
        }
    }
)

data = response.json()

stats = data["data"]["matchedUser"]["submitStats"]["acSubmissionNum"]

easy = medium = hard = total = 0

for item in stats:
    if item["difficulty"] == "Easy":
        easy = item["count"]
    elif item["difficulty"] == "Medium":
        medium = item["count"]
    elif item["difficulty"] == "Hard":
        hard = item["count"]
    elif item["difficulty"] == "All":
        total = item["count"]

content = f"""
Total Solved: **{total}**

🟢 Easy: **{easy}**

🟡 Medium: **{medium}**

🔴 Hard: **{hard}**
"""

with open("README.md", "r", encoding="utf-8") as f:
    readme = f.read()

pattern = r'<!-- LEETCODE_STATS_START -->(.*?)<!-- LEETCODE_STATS_END -->'

replacement = f"""<!-- LEETCODE_STATS_START -->
{content}
<!-- LEETCODE_STATS_END -->"""

readme = re.sub(pattern, replacement, readme, flags=re.DOTALL)

with open("README.md", "w", encoding="utf-8") as f:
    f.write(readme)

print("README updated successfully!")
