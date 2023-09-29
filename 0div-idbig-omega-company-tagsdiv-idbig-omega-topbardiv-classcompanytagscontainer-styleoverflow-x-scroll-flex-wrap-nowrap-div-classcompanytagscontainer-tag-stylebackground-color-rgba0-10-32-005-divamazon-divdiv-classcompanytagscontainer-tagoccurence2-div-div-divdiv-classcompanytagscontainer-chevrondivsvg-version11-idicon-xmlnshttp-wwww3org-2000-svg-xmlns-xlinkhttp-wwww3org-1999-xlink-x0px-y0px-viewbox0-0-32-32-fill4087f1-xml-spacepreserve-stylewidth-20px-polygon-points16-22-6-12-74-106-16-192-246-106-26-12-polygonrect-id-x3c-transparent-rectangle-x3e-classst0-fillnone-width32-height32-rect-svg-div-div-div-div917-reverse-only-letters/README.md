<h2><a href="https://leetcode.com/problems/reverse-only-letters/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Amazon</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>917. Reverse Only Letters</a></h2><h3>Easy</h3><hr><div><p>Given a string <code>s</code>, reverse the string according to the following rules:</p>

<ul>
	<li>All the characters that are not English letters remain in the same position.</li>
	<li>All the English letters (lowercase or uppercase) should be reversed.</li>
</ul>

<p>Return <code>s</code><em> after reversing it</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "ab-cd"
<strong>Output:</strong> "dc-ba"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "a-bC-dEf-ghIj"
<strong>Output:</strong> "j-Ih-gfE-dCba"
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "Test1ng-Leet=code-Q!"
<strong>Output:</strong> "Qedo1ct-eeLg=ntse-T!"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of characters with ASCII values in the range <code>[33, 122]</code>.</li>
	<li><code>s</code> does not contain <code>'\"'</code> or <code>'\\'</code>.</li>
</ul>
</div>